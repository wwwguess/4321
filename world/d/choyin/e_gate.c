// Room: /d/choyin/e_gate.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
    ���������سǵĶ��ţ�һ���ߴ��ʯ��¥������������š�������
�֣�һ����·��������ͨ���ϱߵ�ɽ�ϣ�ʯ��¥�Զ���һֻ��ʨ. ����
�����������, ������һ���ԵñȽ����壬ż��������ҩ, ����֮����
�˳��롣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"e_street1",
  "east" : __DIR__"solidpath1",
]));
        set("objects",([
          __DIR__"npc/cityguard":2,
          __DIR__"npc/ghost":1,
                      ]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
