// Room: /d/sanyen/tower.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����վ����������ǰ, �����һ����Ի: ����������, �ҷ�����
����������������, ��ɽ�����еĸ�ɮ���̺�, ����𻯺����õ���
���Ӿʹ�������������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/sanyen/back_temple",
]));

         set("objects", ([
             __DIR__"npc/work_bonze" : 1 ]) );
	set("no_clean_up", 0);
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
