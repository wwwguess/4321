// Room: /d/choyin/rockyu.c

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
�˵�ɽ��ƽ��,ɽ�¾���������.�������ͩ��ɽ��,���漴Ϊ��ʿ��®����֮��
.�����ɼ���ɽ����ʯС��.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northdown" : __DIR__"rockpath1",
  "westdown" : __DIR__"fence",
  "southup" : __DIR__"tongbhill",
]));

        set("objects", ([
                    __DIR__"npc/oldman" :1,            
                      ]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
