
inherit ROOM;

void create()
{
        set("short", "����ɽ��");
        set("long", @LONG
������ǰ��һ����ͨ��ɽ�塣һ������ܿ�Ҳ����ܶ���ɽ��
�ӱ������������š��������ɽʯд�ţ�����ɽ���������֡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road2",
  "southwest" : "/d/road/cqdukoub",
]));
        set("outdoors", "taoguan");
        setup();
        replace_program(ROOM);
}
