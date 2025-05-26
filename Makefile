

USER=jimhansson

KEYBOARDS += crkbd
#KEYBOARDS += planck
KEYBOARDS += ergodox_ez

crkbd: ARGS = CONVERT_TO=helios
crkbd_variants = rev1
planck_variants = rev3
ergodox_ez_variants = shine glow

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)

SYMLINKS += qmk_firmware/users/$(USER) $(foreach kb,$(KEYBOARDS),qmk_firmware/keyboards/$(kb)/keymaps/$(USER))

qmk_firmware/users/$(USER):
	@echo ===== $@ =====
	ln -s $(shell pwd)/user $@

qmk_firmware/keyboards/%/keymaps/$(USER):
	@echo ===== $@ =====
	ln -sf $(shell pwd)/$* $@ 

update-submodules:
	@echo ===== $@ =====
	git submodule update --init --recursive

pre-setup: update-submodules 
setup: pre-setup $(SYMLINKS)

$(KEYBOARDS): setup
	@echo ===== $@ =====
	cd qmk_firmware && $(ARGS) qmk compile -kb $(subst -,/,$@) -km $(USER) 

# Generic rule for keyboards with variants
define keyboard_with_variants
$(1): $(foreach v,$($(1)_variants),$(1)/$(v))
	@echo ===== $$@ =====
$(1)/%:
	@echo ===== $$@ =====
	cd qmk_firmware && $(ARGS) qmk compile -kb $$@ -km $(USER) 
endef

# Apply the rule to each keyboard that has variants
$(foreach kb,$(KEYBOARDS),$(eval $(call keyboard_with_variants,$(kb))))

# Generic flash rule
flash-%: setup
	@echo ===== Flashing $* =====
	cd qmk_firmware && qmk flash -kb $* -km $(USER)
	rm -f $(SYMLINKS)

# For backward compatibility
flash-ergodox: flash-ergodox_ez-shine
flash-ergodox/shine: flash-ergodox_ez/shine
flash-ergodox/glow: flash-ergodox_ez/glow

clean:
	rm -f $(SYMLINKS)
	make -C qmk_firmware clean
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
	rm -f *.uf2
