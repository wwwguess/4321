// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "����վ");
	set("long", @LONG
�����ǲ�ʯ���Ĺ���վ�����䰫С�ķ�������ɽ�ڽ��졣���ϵ�ɽ��
��һ�������Ա߻�����ɽһ���Ǭ�����ϣ����������õĳ���ͣ���Ա�
��������ȥ�ǲ�ʯ���Ŀյ�������һ����ʯ���̳ɵ�Сб�£�ͨ����ǰ��
����վ�����߲�Զ����һ�������൱�ر�ķ��ᡣ
 
LONG
	);
    set("exits", ([
    "north" : __DIR__"field1",
    "southwest" : __DIR__"station0",
]));
	set("outdoors", "green");
	set("objects", ([
    __DIR__"npc/worker2" :2,
	]) );

	setup();
	replace_program(ROOM);
}
