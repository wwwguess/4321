// Room: /u/k/karrimor/temple/entrance.c

inherit ROOM;

void create()
{
	set("short", "���Ĺ�ǰ");
	set("long", @LONG
������ǰ��һ����ɫ�����ɽ��, ���������ɷ���ıʼ���д��
�����Ĺۡ�����, ��˵�ǵ���̫��������ӹ���ױ����⡣��������
��ȥ��һ���Ĵ�Ĺ㳡����ǰ����һ��ʯӢ������Ľ�������ɽ����
�����¡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" : __DIR__"square",
     "eastdown" : __DIR__"ladder1",
]));

    set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
