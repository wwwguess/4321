// Room: /d/village/farmhouse1.c

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
���ũ���ڵİ���ǳ����أ���ʮ�־�������������˳�Ŵ���������
������ķĳ��ϣ����ϰ�����������ߣ��ر��������ϻ������̬������
�ã�ɫ�ʱ��棬�Ա߻�����һ��ľ�������ܶ��Ǹ�������С������ߡ�һ
�Ŵ󴲵��Ա߻���һ��С�������ݵı�����ũ��ĺ�Ժ���ϱ߳����ݾ���
�������ʯС·��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fmhousback.c",
  "south" : __DIR__"road4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
