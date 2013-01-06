SUBDIRS = projects/wyse-840366-01 projects/keypad
SUBCLEAN = $(addsuffix .clean,$(SUBDIRS))

.PHONY: subdirs $(SUBDIRS) clean $(SUBCLEAN)

subdirs : $(SUBDIRS)

$(SUBDIRS) :
	$(MAKE) -C $@

clean : $(SUBCLEAN)

$(SUBCLEAN) : %.clean:
	$(MAKE) -C $* clean
