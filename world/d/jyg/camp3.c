// ROOM:__DIR__"camp3"

inherit ROOM;
void create()
{
        set("short","С��Ӫ��");
	set("long",@LONG                                   
���Ǹ���ţƤ���Ϻ��޲�����ɵ�СӪ�ʣ�����ֻ��������С����������
С�����������һ��С��Ӫ����Ĳ�����ɣ����������ǳ����Ӫ�Ĵ��š�
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
