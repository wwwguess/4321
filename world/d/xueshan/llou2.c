//by dwolf
//llou2.c

#include <ansi.h>
inherit ROOM;
              
string* objects = ({
	"pipe", 
	"zhuxiao",
	"chabei",
});
	
void create()
{       
	int i = random(sizeof(objects));
	set("short", RED"藏宝库"NOR);
	set("long", @LONG
	  你眼前一亮，一个新的世界出现在能你面前。满屋子都是宝贝，可惜苗
人凤只让你拿一样。这儿有一条地道可以通向雪山山脚。
LONG
	); 
	set("exits", ([
		"down" : __DIR__"foot.c",
	]));                            
	set("objects", ([
		__DIR__"npc/obj/"+ objects[i] : 1]));
	setup();
}
