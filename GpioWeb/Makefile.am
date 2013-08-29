
EXTRA_DIST =  

# Warning: This is an automatically generated file, do not edit!

if ENABLE_DEBUG
ASSEMBLY_COMPILER_COMMAND = dmcs
ASSEMBLY_COMPILER_FLAGS =  -noconfig -codepage:utf8 -warn:4 -optimize- -debug "-define:DEBUG;"
ASSEMBLY = bin/GpioWeb.dll
ASSEMBLY_MDB = $(ASSEMBLY).mdb
COMPILE_TARGET = library
PROJECT_REFERENCES =  \
	../pcDuino.Net/bin/Debug/pcDuino.Net.dll
BUILD_DIR = bin

GPIOWEB_DLL_MDB_SOURCE=bin/GpioWeb.dll.mdb
GPIOWEB_DLL_MDB=$(BUILD_DIR)/bin/GpioWeb.dll.mdb
PCDUINO_NET_DLL_SOURCE=../pcDuino.Net/bin/Debug/pcDuino.Net.dll
PCDUINO_NET_DLL_MDB_SOURCE=../pcDuino.Net/bin/Debug/pcDuino.Net.dll.mdb
PCDUINO_NET_DLL_MDB=$(BUILD_DIR)/bin/pcDuino.Net.dll.mdb
GLOBAL_ASAX_SOURCE=Global.asax
WEB_CONFIG_SOURCE=web.config
DEFAULT_ASPX_SOURCE=Default.aspx

endif

if ENABLE_RELEASE
ASSEMBLY_COMPILER_COMMAND = dmcs
ASSEMBLY_COMPILER_FLAGS =  -noconfig -codepage:utf8 -warn:4 -optimize-
ASSEMBLY = bin/GpioWeb.dll
ASSEMBLY_MDB = 
COMPILE_TARGET = library
PROJECT_REFERENCES =  \
	../pcDuino.Net/bin/Release/pcDuino.Net.dll
BUILD_DIR = bin

GPIOWEB_DLL_MDB=
PCDUINO_NET_DLL_SOURCE=../pcDuino.Net/bin/Release/pcDuino.Net.dll
PCDUINO_NET_DLL_MDB=
GLOBAL_ASAX_SOURCE=Global.asax
WEB_CONFIG_SOURCE=web.config
DEFAULT_ASPX_SOURCE=Default.aspx

endif

AL=al
SATELLITE_ASSEMBLY_NAME=$(notdir $(basename $(ASSEMBLY))).resources.dll

PROGRAMFILES_BIN = \
	$(GPIOWEB_DLL_MDB) \
	$(PCDUINO_NET_DLL) \
	$(PCDUINO_NET_DLL_MDB)  

LINUX_PKGCONFIG = \
	$(GPIOWEB_PC)  

PROGRAMFILES = \
	$(GLOBAL_ASAX) \
	$(WEB_CONFIG) \
	$(DEFAULT_ASPX)  


RESGEN=resgen2
	
all: $(ASSEMBLY) $(PROGRAMFILES_BIN) $(LINUX_PKGCONFIG) $(PROGRAMFILES) 

FILES = \
	Global.asax.cs \
	Default.aspx.cs \
	Default.aspx.designer.cs 

DATA_FILES = 

RESOURCES = 

EXTRAS = \
	Global.asax \
	web.config \
	Default.aspx \
	gpioweb.pc.in 

REFERENCES =  \
	System \
	System.Web \
	System.Xml \
	System.Web.Services

DLL_REFERENCES = 

CLEANFILES = $(PROGRAMFILES_BIN) $(LINUX_PKGCONFIG) $(PROGRAMFILES) 

include $(top_srcdir)/Makefile.include

PCDUINO_NET_DLL = $(BUILD_DIR)/bin/pcDuino.Net.dll
GPIOWEB_PC = $(BUILD_DIR)/gpioweb.pc
GLOBAL_ASAX = $(BUILD_DIR)/Global.asax
WEB_CONFIG = $(BUILD_DIR)/web.config
DEFAULT_ASPX = $(BUILD_DIR)/Default.aspx

$(eval $(call emit-deploy-target,GPIOWEB_DLL_MDB))
$(eval $(call emit-deploy-target,PCDUINO_NET_DLL))
$(eval $(call emit-deploy-target,PCDUINO_NET_DLL_MDB))
$(eval $(call emit-deploy-wrapper,GPIOWEB_PC,gpioweb.pc))
$(eval $(call emit-deploy-target,GLOBAL_ASAX))
$(eval $(call emit-deploy-target,WEB_CONFIG))
$(eval $(call emit-deploy-target,DEFAULT_ASPX))


$(eval $(call emit_resgen_targets))
$(build_xamlg_list): %.xaml.g.cs: %.xaml
	xamlg '$<'

$(ASSEMBLY_MDB): $(ASSEMBLY)

$(ASSEMBLY): $(build_sources) $(build_resources) $(build_datafiles) $(DLL_REFERENCES) $(PROJECT_REFERENCES) $(build_xamlg_list) $(build_satellite_assembly_list)
	mkdir -p $(shell dirname $(ASSEMBLY))
	$(ASSEMBLY_COMPILER_COMMAND) $(ASSEMBLY_COMPILER_FLAGS) -out:$(ASSEMBLY) -target:$(COMPILE_TARGET) $(build_sources_embed) $(build_resources_embed) $(build_references_ref)
