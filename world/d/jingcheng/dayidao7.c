// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

inherit ROOM;

void create()
{
      set("short","大驿道");
	set("long", @LONG
    这是一条宽阔笔直的驿道，足可容得下十马并驰。往南通向
保定，往北则直达京城。这是通往京城必经之路，大道两边
种着高耸挺拔的杨树。路上三三两两的有行人来往于京城与
保定之间.
LONG
	);

	set("exits", ([
 "southwest" :__DIR__"dayidao6",
 "northdown" :__DIR__"dayidao8",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

