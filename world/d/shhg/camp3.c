// ROOM:__DIR__"camp3"

inherit ROOM;
void create()
{
        set("short","С��Ӫ��");
	set("long",@LONG                                   
���Ǹ��ɴ��ԵĲ�������ɵ�СӪ�ʣ�����ֻ��������С����������
С�����������һ��С��Ӫ�ʡ��Ĳ�����ɣ�����������С�ӳ���Ӫ�ʡ�
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1*/
		"south" : __DIR__"camp1",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/guard1" : 2,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
