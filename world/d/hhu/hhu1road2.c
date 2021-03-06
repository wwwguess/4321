#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "林荫道");
        set("long", @LONG
这是校内的一条林荫道。
	    周围很安静，只有树叶被风吹动的沙沙声和小鸟欢快的叫声。
	风吹在你的脸上凉凉的，感觉特别舒服。抬头是绿树盖顶，低头
	是芳草落英，你好象至身于世外桃源，忘记了江湖险恶，血雨腥
	风，情仇恩怨，争名夺利。一切都是那么美好，你真想在这里度
	过余生，从此淡出江湖，不问武林中事。
	这里一边是高高的图书馆，馆名还是茅以升题的。一边是管理楼，
	墙上的海报栏中贴着一张很有气势的大海报(sign).
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :)
        ]) );

        set("exits", ([ /* sizeof() == 2 */
		  "southwest" :__DIR__"downroad",
		  "northeast" :__DIR__"hhu1road1",
	]));

 //       set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}

string look_sign(object me)
{
	return "海报上写着：\n
=========倚剑笑江湖     恃才傲河海=========\n
    谨以此MUD游戏纪念存在过的计算机学院\n
             97届应用班网络班 
\n         以及两个班的78名同学\n
                                   By Jenny\n
			               1997年7月\n";
}

