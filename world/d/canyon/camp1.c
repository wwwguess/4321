// ROOM:__DIR__"camp1"

inherit ROOM;
void create()
{
        set("short","��Ӫ���");
	set("long",@LONG                                   
�˴�Ϊ��ʯ����פ������ڣ�����Ϊ������ʳ�ĵط������ſڵ�����
����λС������ֵ�ڡ��ϡ�������ΪС����Ӫ�ʡ�
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==4 */
		"west" : __DIR__"canyon4",
        	"north" : __DIR__"camp3",
        	"south" : __DIR__"camp4",
        	"east" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/door_guard" : 2,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
