#include <ansi.h>
#include <weapon.h>

inherit HAMMER; 

void create()
{
        set_name(  "箱子" , ({ "case" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long",

"这是一个普普通通的箱子。你可用它（make）或（remake）兵器。\n"
);
                set("value", 1);
                set("material", "wood");
                set("rigidity", 100000);
                set("weapon_prop/agility", 0); 
                set("weapon_prop/personality", 0);
        }

        init_hammer(120);
        setup();

}
 
void init()
{
	add_action("do_make","make");
}

int do_make(string arg)
{
	object me;
	object obj;
	me=this_player();
	if(!arg) return 0;
	{
		if(arg=="axe")        {obj=new(__DIR__"cmaxe");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把斧。\n");}
        	if(arg=="blade")      {obj=new(__DIR__"cmblade");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把刀。\n");}     	
		if(arg=="dagger")     {obj=new(__DIR__"cmdagger");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把匕首。\n");}
        	if(arg=="fork")       {obj=new(__DIR__"cmfork");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把叉。\n");}
        	if(arg=="hammer")     {obj=new(__DIR__"cmhammer");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把锤。\n");}
        	if(arg=="staff")      {obj=new(__DIR__"cmstaff");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把杖。\n");}   
	     	if(arg=="sword")      {obj=new(__DIR__"cmsword");obj->move(me);  
write("你将手中的箱子打开，用其中的零件拼成了一把剑。\n");}
        	if(arg=="whip")       {obj=new(__DIR__"cmwhip");obj->move(me);
write("你将手中的箱子打开，用其中的零件拼成了一把鞭。\n");}		
		destruct(this_object());
		
	}
	return 1;
}          
  