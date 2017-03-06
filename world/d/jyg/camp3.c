// ROOM:__DIR__"camp3"

inherit ROOM;
void create()
{
        set("short","小兵营帐");
	set("long",@LONG                                   
这是个由牛皮加上厚棉布所搭成的小营帐，里面只有三二个小兵，其他的
小兵，大概在另一个小兵营帐里赌博聊天吧，而东边则是出入兵营的大门。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1*/
		"east" : __DIR__"camp1",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/xinbing" : 2,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
