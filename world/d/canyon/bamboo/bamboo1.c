// Room: /d/canyon/bamboo/bamboo1.c

inherit ROOM;

void create()
{
	set("short", "���ֵ����");
	set("long", @LONG
�޳�������ӳ�����������ޱߣ�������Σ��ҷ�����ζ������
���Ư���������������崺�磬�������������ֵ�����վ�����е���
�����侳�����Ȼ���ʣ���ȴ�˽������ն���ֹ�ڴˣ�һֱ������
֮�����Գ��Ӵ�����֮�����ۺ���ʹ�����ҵ㿴���Ӵ˰�̩֮�ص�
�����Ǻεȵ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"bamboo2",
		"back" : "/d/canyon/fantasy1",
]));

	setup();
	replace_program(ROOM);
}
