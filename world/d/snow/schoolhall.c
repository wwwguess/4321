// Room: /d/snow/schoolhall.c

inherit ROOM;

void create()
{
	set("short", "������ݴ���");
	set("long", @LONG
�����Ǵ�����ݵ�����������̫ʦ��һ���ſ�������ſڣ�������
������λ��ʦ����������������λ����һ����ݲ�ͬ���ǣ�ǽ�Ͼ�Ȼ
�������������Ϊ���׵��黭����ʾ��������˲��Ǵ��ֲ�ʶ�Ĵֺ���
��������˫ȫ�ĸ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zlroom",
  "west" : __DIR__"school2",
  "east" : __DIR__"inneryard",
]));
	set("objects", ([
		CLASS_D("swordsman") + "/master":1 ]) );
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
	"obj/board/swordsman_b"->foo();
}
