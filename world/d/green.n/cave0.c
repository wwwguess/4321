// Mon  08-21-95

inherit ROOM;
 
void create()
{
        set("short", "����");
        set("long", @LONG
������ɽ�������, ���Ͽ�ȥ��һ��СС����ʯ·, ���Գ���
�Ӳ�, �����ܲ�����. ������һ������ľ��, ������һ���ֱ۴�
������˩��. ��Ȼ���, ���Կ��Ըе�һ�ɺ���������͸����.
 
LONG
        );
       set("exits", ([
       "south" : __DIR__"path0",
]));
 
        set("objects", ([
        __DIR__"npc/kid4" : 2,
		]) );
        setup();
        replace_program(ROOM);
}
 
