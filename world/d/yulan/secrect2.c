inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ��խС�����ң������ǰֻ��һ����ڵ�С·��·�ľ�ͷ�ֳ�һ�����⡣
LONG
	);

        set("exits", ([ /* sizeof() == 3 */
            "west" : "/d/yulan/secrect1",
            "east" : "/d/yulan/xiaolu",
]));

	setup();
	replace_program(ROOM);
}
