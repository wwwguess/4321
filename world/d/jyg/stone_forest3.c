// Room: /d/canyon/stone_forest3.c

inherit ROOM;

void create()
{
	set("short", "�λ��Ծ����");
	set("long", @LONG
������������������ž���������һ�����ΰɣ������˻�ʯ��
��·��һ������Ĺ�ע��Ȼ���䵽������ϣ��������ڴ��磬����ˬ
�ʼ��ˣ�����Ա������صľ��Ӿ�Ȼ�������˲��ɿ��ܵ�ѹ��������
�߳ߵط������淴���չ⣬ǿ�ջ�ʯ����·���뵽����������Ī����
�־壬��Ī���б����������Ŀ־壬������뿪������һ˲�䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"mirror" : __DIR__"fantasy1",
		"east" : __DIR__"stone_forest2",
]));

	setup();
	replace_program(ROOM);
}
