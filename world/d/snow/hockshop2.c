// Room: /d/snow/hockshop2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ƿ�ǵ��̵Ĵ����ң���ʱ������Ĵ󳯷�������治��
�����������ó�������������������ֻ�ܿ���һ�������������ӡ�����
�ߴ���һ���������Իص����̵��档
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/snow/hockshop",
]));

	setup();
	replace_program(ROOM);
}
