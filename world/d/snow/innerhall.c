// Room: /d/snow/innerhall.c

inherit ROOM;

void create()
{
	set("short", "�����Ժ");
	set("long", @LONG
�����Ǵ�����ݵ���Ժ��ƽ����ݵ���û�й����������ǲ��ҵ���
�����ģ����������ҵ����ã������ͼҾ���Է��ֱ�λ������һ���ߵ�
�����ԣ������Լ��񷿡����۵��Է��������ϵ��ߵ����ԣ�����������
����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/snow/inneryard",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
