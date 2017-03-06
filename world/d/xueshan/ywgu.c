// ywgu.c
//by dwolf  
  
#include <ansi.h>
inherit ROOM;

string look_board();

void create()
{
	set("short", YEL"药王谷"NOR);
	set("long", @LONG
	  你沿着小路向下走，一间草棚出现在你面前，门前有一块牌子(board)，
一个女孩子正坐在门前的藤椅上看书，一副悠闲的样子。
LONG
	);

	set("exits", ([
		"up" : __DIR__"foot.c", 
	 ]));  
	set("objects", ([
		__DIR__"npc/cheng" : 1,
	]));                   
	set("item_desc", ([
		"board" : (: look_board :),
	]));
	setup();
}                   

string look_board()
{
	return YEL"\n本谷引进先进科技，为大家美容，健美。规则如下：\n
\n 	凡是经验在500000以上，可接受一次美容，或者一次健美手术。 其中：\n
\n 	美容耗一次10000exp,健美耗一次15000exp,welcome!!!!\n\n"NOR;
}
		

void reset()
{
    ::reset();
    if(query("exits/down"))
    	delete("exits/down");
}


                                                