//by dwolf
//97.11.13                 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "森林边缘");
	set("long", @LONG
	  你来到森林边缘，远处传来猛兽的吼声，让人心惊。路旁有一破旧小庙
，庙门两旁有一幅不甚工整的对联：王侯将相谁来都可，高矮胖瘦那个也行。横批
：谁来吃谁。远处惨兮兮，兮兮惨。
LONG
	); 
	set("exits", ([
		"north" : __DIR__"forest1.c",  
		"east" : "/d/suzhou/szroad9",
]));
	setup();
	replace_program(ROOM);
}
