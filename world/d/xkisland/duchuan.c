//xk island.inboat.c   
//dan
inherit ROOM;




void create()
{
	set("short", "海船");
	set("long", @LONG
一叶小舟，最多也就能载两,三个人。一名三十多岁的船夫
手扶桨，正在船尾吃力地摇着船。
LONG
	);


	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



