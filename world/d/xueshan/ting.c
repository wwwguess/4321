//by dwolf
          
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"大厅"NOR);
	set("long", @LONG
	  你站在这儿，仿佛站在大广场一样。点点宝石的微光从天花板上照下来，
好象天幕的繁星。不相称的是地板上铺着几块青砖，你刚为找到毛病而自鸣得意，
却发现旁边有一行小字：此砖来自巴黎墙，不可不看。一个威严的老者坐在厅中央
的狐皮椅子上，对你的到来理也不理，不知道是谁，
LONG
	);
	set("exits", ([
		"north" : __DIR__"guarden2.c",
		"south" : __DIR__"guarden.c",
]));         
	setup();
} 


		
	                                      
 		

