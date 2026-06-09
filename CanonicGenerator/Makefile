NAME = newclass

INSTALL_DIR = $(HOME)/bin/NewClass
SCRIPT = newclass
TEMPLATES_DIR = templates
SHELL_RC = $(HOME)/.zshrc

all:
	@echo "Usage:"
	@echo "  make install   -> install NewClass tool"
	@echo "  make uninstall -> remove NewClass tool"

install:
	@echo "Installing NewClass..."
	@mkdir -p $(INSTALL_DIR)
	@mkdir -p $(INSTALL_DIR)/$(TEMPLATES_DIR)

	@cp $(SCRIPT) $(INSTALL_DIR)/
	@cp $(TEMPLATES_DIR)/* $(INSTALL_DIR)/$(TEMPLATES_DIR)/

	@chmod +x $(INSTALL_DIR)/$(SCRIPT)

	@if ! grep -q "$(INSTALL_DIR)" $(SHELL_RC); then \
		echo 'export PATH="$(INSTALL_DIR):$$PATH"' >> $(SHELL_RC); \
		echo "PATH added to $(SHELL_RC)"; \
	else \
		echo "PATH already set"; \
	fi

	@echo "Done. Restart terminal or run: source $(SHELL_RC)"

uninstall:
	@echo "Uninstalling NewClass..."
	@rm -rf $(INSTALL_DIR)
	@echo "Removed $(INSTALL_DIR)"

reinstall: uninstall install

clean:
	@echo "Nothing to clean (install tool only)"

.PHONY: all install uninstall reinstall clean
