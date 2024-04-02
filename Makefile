

USER=jimhansson

KEYBOARDS += crkbd
#KEYBOARDS += planck
KEYBOARDS += ergodox_ez
#KEYBOARDS += ergodox_ez

crkbd: ARGS = CONVERT_TO=helios
crkbd: variant = rev1
planck: variant = rev3
#ergodox_ez: variant = shine
ergodox_ez: variant = glow

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)

pre-setup:
	@echo ===== $@ =====
	git submodule update --init --recursive
	rm -rf qmk_firmware/users/$(USER)
	for k in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$$k/keymaps/$(USER); done;

$(KEYBOARDS): pre-setup
	@echo ===== $@ =====

	rm -rf qmk_firmware/keyboards/$@/keymaps/$(USER)

# add new symlinks
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$@/keymaps/$(USER)

# run lint check
	#cd qmk_firmware; qmk lint -km $(USER) -kb $@

# run build
	make BUILD_DIR=$(shell pwd) -j1 -C qmk_firmware $@/$(variant):$(USER) $(ARGS)

# cleanup symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$$f/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
	rm -f *.uf2
