// Room: /d/temple/ladder5.c

inherit ROOM;

void create()
{
	set("short", "ʯӢ��ʯ��");
	set("long", @LONG
����վ������ݵ����, ����ɫ����ʯӢ�ҽ������Ѷ���, ����
���ɽɫ���γ�һ������ɫ�ľ�����̧ͷ����ʯ�׾�ͷ����������, ��
Ȼ����������Ѿ������������ºۼ�, ���Բ�ʧ��ׯ����ʥ����Ϣ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"ladder4",
  "eastdown" : __DIR__"sroad",
]));
	set("no_clean_up", 0);
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
