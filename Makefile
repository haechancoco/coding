CC      := gcc
CSTD    := gnu17            # 필요시 c17로 변경 가능
WARN    := -Wall -Wextra -Wconversion -Wshadow
OPT     := -O2
# 헤더 폴더가 있다면 아래에 -Iinclude 같이 추가
INCS    := 
DEFS    :=                 # 필요 매크로가 있으면 -DMYDEF=1 형태로 추가

CFLAGS  := -std=$(CSTD) $(WARN) $(OPT) $(INCS) $(DEFS)
LDFLAGS :=                 # 필요시 라이브러리 링크(-lm 등) 추가

SRC     := $(wildcard *.c)
OBJDIR  := build
OBJ     := $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))
BIN     := app

.PHONY: all clean
all: $(BIN)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

clean:
	rm -rf $(OBJDIR) $(BIN)
