// Room: /d/sanyen/tunnele.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���߽���һ���䴩ɽ�ڿ��ɵ����������������ĳ��ڣ�������Զ
��Ҳ���Դ������Ƽ����ߵĳ��ڣ�һ����ǵ�ζ����������д�������
�����������Ȫ���ǻ�ɽ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/sanyen/tunnel",
  "east" : "/d/sanyen/gate",
]));

	setup();
	replace_program(ROOM);
}
