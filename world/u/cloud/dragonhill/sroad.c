// Room: /u/cloud/dragonhill/sroad.c

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������ѩͤ��ͨ�������ıؾ�֮·�������������򣬱���ͨ��
�����ڡ����ȹٸ����ڴ�������·�����������ε������ޣ���������
���ϳ���ǿ�˳�û��ֻ�����ա���˵����·���ɹ������˺ܶ࣬·����
���ȵú�ƽ�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"shillfoot",
  "southeast" : "u/cloud/entrance"
]));
        set("outdoors", "dragonhill");

        setup();
        replace_program(ROOM);
}
