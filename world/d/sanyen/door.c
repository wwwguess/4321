// Room: /d/sanyen/door.c

inherit ROOM;

void create()
{
	set("short", "ɽ��������");
	set("long", @LONG
��������ǰ����һ����ΰ׳��������, �Ϸ�����������Ƭ, ��
Ƭ���·�����һ������Ҷ�, ����д����ɽ���¡������̽���֡���
�еĴ����������ر���, ֻ����ӭ�Ӵ�����ʱ�ŻῪ��������ֻ����
���Ե�ƫ�š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/sanyen/road1",
  "south" : "/d/sanyen/front_yard",
]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
