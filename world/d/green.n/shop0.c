// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��������ʯ��Ψһ���̵� -- �������, �����������Թ���
�ճ�������Ʒ, ����, �����ڹײ�. �����˵��һ�䡸�ӡ�����.
�����൱��ӵ��, �����������Ӻ�����.

LONG
	);
    set("exits", ([
    "west" : __DIR__"path4",
]));
	set("objects", ([
    __DIR__"npc/shen" : 1,
    __DIR__"npc/woman1" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
