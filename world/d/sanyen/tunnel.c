// Room: /d/sanyen/tunnel.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���߽���һ���䴩ɽ�ڿ��ɵ���������Ҳ��������Լ�ߡ�������
�ң����߾�������ĳ��ڣ������������ŵ�һ����ǵ�ζ���������
��������Ȫ���ǻ�ɽ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/sanyen/sroad2",
  "east" : "/d/sanyen/tunnele",
]));

	setup();
	replace_program(ROOM);
}
