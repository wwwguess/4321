
inherit ROOM;

void create()
{
        set("short", "山谷口");
        set("long", @LONG
路边立着一块石碑，上面写着两个古篆字：崂山。        
往山谷看去，一条弯弯曲曲的小路伸向谷内，但在一危崖前突然中断。
LONG
        );
        set("exits", ([ 
  "northup" : "/u/taoguan/road1",
  "eastdown" : __DIR__"troad1",
]));
	set("outdoors","tieflag"); 	
        
        setup();
}

