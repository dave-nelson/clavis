SUBDIRS = projects/keypad	 	\
	  projects/wyse-840358-01	\
	  projects/wyse-840366-01

SUBCLEAN = $(addsuffix .clean,$(SUBDIRS))

.PHONY: subdirs $(SUBDIRS) clean $(SUBCLEAN)

subdirs : $(SUBDIRS)

$(SUBDIRS) :
	$(MAKE) -C $@

clean : $(SUBCLEAN)

$(SUBCLEAN) : %.clean:
	$(MAKE) -C $* clean
