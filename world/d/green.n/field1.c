// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "��ʯ���Ŀյ�");
	set("long", @LONG
����һƬ�����յأ����ܶ���һЩ�и�����Ĵ�ʯ�����ʯ��������
ȥ���ǲ�ʯ�������ʵ�ʯ赾�������Ĳ����Ѿ�������ԭ����ģ���ˡ���
�Ͽ�ȥ��һЩ��С�ķ���ʹ��湤�ߵĵط��������Ǵ��ڵĹ㳡��������
���㳡�ĵط���һ����ª����լ��һ�����Ǻ����Ե�С·������լ������
��ͨȥ��
 
LONG
	);
    set("exits", ([
    "west" : __DIR__"field0",
    "south" : __DIR__"station1",
    "north" : __DIR__"house3",
    "northeast" : __DIR__"field2",
]));
	set("objects", ([
    __DIR__"npc/kid1" : 1,
	]) );
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
