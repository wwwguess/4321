// ROOM:__DIR__"camp8"

inherit ROOM;
void create()
{
        set("short","�󽫾�Ӫ��");
	set("long",@LONG                                   
������Ǵ󽫾���Ӫ�ʣ����õĲ�����������Ҳ���ǻ�����
���ڲ�ͬ�ĵط�������һ������ľ�����ڷ�������������鼮��
��������������ֻ���书���ͽ�������һλ����ѧ�ʵ����ߡ�
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1*/
        	"north" : __DIR__"camp7",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/general" : 1,
		__DIR__"npc/adviser" : 1,
	]) );
	
	setup();
	
//	replace_program(ROOM);
} //EOF
