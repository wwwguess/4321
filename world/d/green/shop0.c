// Room: /d/green/shop0.c

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
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/green/path4",
]));
	set("objects", ([
	"/d/green/npc/shen" : 1,
	"/d/green/npc/woman1" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
