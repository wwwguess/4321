// Room: /u/cloud/eroad2.c

inherit ROOM;

void create()
{
        set("short", "�����ֵ�");
        set("long", @LONG
����������򶫣�ͨ���賡��·���ϱ���һ�������Ĵ��ھ� -- ��
Զ�ھ֡�����������żҵ�լԺ��

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/eroad1",
  "north" : "/u/cloud/park",
  "south" : "/u/cloud/biaoju",
  "northeast" : "/u/cloud/eroad3",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

