// Room: /d/choyin/crossroad.c

inherit ROOM;

void create()
{
	set("short", "ʮ��·��");
	set("long", @LONG
�����ǲ�ƽ�ָ��а��ֵĽ���·�ڣ����Ͼ��������سǵ����ţ���
����Զ���������ŵ����ڵأ������ص��������Եø��ⰲ����·�˴��
��Ĭ�����������Ҵ����������ͳǶ��Ļ���������ȣ������Ե�������
�ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"s_gate",
		"north" : __DIR__"court1",
		"east" : __DIR__"s_street5",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
