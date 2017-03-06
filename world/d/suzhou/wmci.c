//ROOM:/d/suzhou/wmci.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;            

void create()
{                           
	set("short", RED"武穆祠"NOR);
	set("long", @LONG
        	 这是武穆公岳飞的祠堂，岳飞被秦桧害死后，他的躯体埋在杭州西
湖边，但祠堂却建在苏州。谁也不知道为什么。这里香火很旺，男男女女都来朝拜这位
民族英雄。你也许也该给他磕头(ketou)。
LONG
	);                                        
	set("exits", ([
		"west" : __DIR__"nroad1", 
]));             
	set("objects", ([
		__DIR__"npc/girl.c" : 1,    
		__DIR__"npc/woman.c" : 1,
]));
	setup();
}              

void init()
{
	add_action("do_ketou", "ketou");
}

int do_ketou()(string arg)
{
	object me;
	me = this_player(); 
	                  
	if (me->query("combat_exp") >= 500000) {
		message_vision("你磕着头，突然地下开了一个洞，你掉了进去。");
		me->move("/d/suzhou/mishi");  
	}
  
	if ( me->query("chao_ting") <= 1000) {
	me->add("chao_ting", 1);
	me->add("gin", -1);
	message_vision("你恭恭敬敬地跪下，对着岳元帅的神像磕头。你的朝廷忠诚度升高了。\n");
	}
	else {
		return	"你对着岳元帅的神像恭恭敬敬的磕了一个头。";
	}                   

	if (me->query("combat_exp") >= 500000) {
	me->move("/d/suzhou/mishi");
}
	
  

