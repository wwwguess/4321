// Room: /d/shaolin/nvqinshi.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "女寝室");
	set("long", @LONG
这里是女寝室。靠墙一溜摆着几张木床，床上
有柔软的被褥，让人一看就想睡。
LONG
	);
	set("sleep_room",1);

	set("exits", ([
		"north" : __DIR__"yushimen",
		
	]));

	setup();
        replace_program(ROOM);
}



