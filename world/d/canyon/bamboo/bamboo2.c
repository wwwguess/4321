// Room: /d/canyon/bamboo/bamboo2.c

inherit ROOM;

void create()
{
	set("short", "���ֵ�");
	set("long", @LONG
�˴������ֱ�����ڵ����Ӹ�Ϊ�ߴ���ֱ��Ҳ��ЩС����������
��������ȥ��������ȥ�ģ�����������Ȼ����ʱ��Ҳ��ݺ����������
��ʫ�䣬������Ȼ���˼��ɾ���ֻ��ż�����ǹ����ǿ��Ϯ����£�
�����������ܣ�������̽ͷ����һ���˴�Ļ�ʯͦ�����ڣ���������
����ԼԼ��Щ��������ɢ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"bamboo3",
		"south" : __DIR__"bamboo1",
]));

	setup();
	replace_program(ROOM);
}
