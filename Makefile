

USER=jimhansson
#KEYBOARDS = ergodox_ez/glow ergodox_ez/shine planck/rev3 crkbd/rev1
KEYBOARDS = crkbd


all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)

$(KEYBOARDS):
	git submodule update --init --recursive

	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$@/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

# add new symlinks
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$@/keymaps/$(USER)

# run lint check
#	cd qmk_firmware; qmk lint -km $(USER) -kb $@ --strict

# run build
	make BUILD_DIR=$(shell pwd) -j1 -C qmk_firmware $@:$(USER) CONVERT_TO=helios

# cleanup symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
