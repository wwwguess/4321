// Room: /u/cloud/eroad1.c

inherit ROOM;

void create()
{
        set("short", "�����ֵ�");
        set("long", @LONG
������ʮ��·�ڵĶ��࣬���߷����ﶼ��Ϊ���֡������ƺ��ǼҴ�
¥����ʱ�������糾Ů�ӵ���Ц��������ȴ��Щ���̾�����������ߺ��
���壬���ǼҶĳ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/cross",
  "north" : "/u/cloud/jiyuan",
  "south" : "/u/cloud/duchang",
  "east" : "/u/cloud/eroad2",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

