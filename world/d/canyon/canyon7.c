// Room: /d/canyon/canyon7.c

inherit ROOM;

void create()
{
	set("short", "���չعȵ�");
	set("long", @LONG
���չ����������£��м��ǹȵأ���״�������յ�˫�壬�ɴ˵�����
��������վ�������ͨ����ʦ�����ϳ��ˡ��������ޡ�ѩͤ�����������
������ˣ������Ǳ��ұ���֮�ء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : "/d/village/road1",
  		"north" : __DIR__"canyon6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
