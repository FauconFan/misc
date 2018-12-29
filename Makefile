
OCAMLMAKEFILE = OCamlMakefile

RESULT = mondrian

MAIN = src/Main.ml

TAR = durand-priou.tar.gz
TAR_DIR = $(basename $(basename $(TAR)))

ML_FILES = \
		src/model/solveur/sat_solver.ml \
		src/utils/CLIParser.ml \
		src/utils/Option.ml \
		src/utils/Combinatorics.ml \
		src/model/ModelConstant.ml \
		src/model/Base.ml \
		src/model/Bsp.ml \
		src/model/FNC.ml \
		src/controller/Interact.ml \
		src/model/Check.ml \
		src/model/Generation.ml \
		src/view/GraphicsConstant.ml \
		src/view/SLAC.ml \
		src/view/components/Background.ml \
		src/view/components/Button.ml \
		src/view/components/ButtonColor.ml \
		src/view/components/Cursor.ml \
		src/view/components/Popup.ml \
		src/view/components/Text.ml \
		src/view/components/FrameBSP.ml \
		src/view/GMessage.ml \
		src/view/GraphicsManager.ml \
		src/view/CampingScene.ml \

LIBS = graphics unix

MLI_FILES = $(ML_FILES:%.ml=%.mli)

SOURCES = $(MLI_FILES) $(ML_FILES) $(MAIN)

.PHONY: all
all: nc

.PHONY: help
help:
	@printf "Useful commands for this Makefile:\\n"
	@printf " - help : prints this message\\n"
	@printf " - mondrian : same as nc\\n"
	@printf " - exec : compiles and runs\\n"
	@printf " - bytecode (bc) : compiles in bytecode\\n"
	@printf " - nativecode (nc) : compiles in nativecode\\n"
	@printf " - cleanup : removes compiled files, keeps executables\\n"
	@printf " - clean : removes all compiled files\\n"
	@printf " - clean-all : removes all generated files (doc includes)\\n"
	@printf " - clean-doc : removes all docs files\\n"
	@printf " - fclean : same as clean-all\\n"
	@printf " - re : cleans all and recompiles\\n"

$(RESULT): nc

.PHONY: exec
exec: $(RESULT)
	./$(RESULT)

.PHONY: fclean
fclean: clean-all
	rm -f $(TAR)

.PHONY: re
re: fclean $(RESULT)

.PHONY: tar
tar: $(TAR)

$(TAR): fclean
	mkdir -p $(TAR_DIR)
	cp -r src/ Makefile $(OCAMLMAKEFILE) README.md $(TAR_DIR)
	tar -czf $@ $(TAR_DIR)
	rm -rf $(TAR_DIR)

include $(OCAMLMAKEFILE)
