// Room: /u/cloud/dragonhill/nroad.c

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������ѩͤ��ͨ�������ıؾ�֮·���������ѩͤ������ͨ��
�����ڡ����ȹٸ����ڴ�������·�����������ε������ޣ���������
���ϳ���ǿ�˳�û��ֻ�����ա���˵����·���ɹ������˺ܶ࣬·����
���ȵú�ƽ�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/snow/sroad1",
  "southeast" : __DIR__"nhillfoot",
]));
        set("outdoors", "dragonhill");

        setup();
        replace_program(ROOM);
}
