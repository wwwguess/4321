// REDGIRL.C
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(RED "������Ů" NOR, ({ "red girl","girl" }) );
        set("long", "������ɴ��˿��������˪����˿Ʈ�\n");
        set("age", 16);
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("combat_exp", random(500000));  
	set("kee", 3000);
        set("eff_kee", 3000);
        set("max_kee", 3000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "\n",
        }) );
        setup();
        armor=new(__DIR__"obj/corclot");
	armor->set_name(RED "����" NOR,({"red cloth","cloth"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corclasp");
	armor->set_name(RED "����" NOR,({"red bangle","bangle"}) );
	armor->move(this_object());
	armor->wear();	
	armor=new(__DIR__"obj/corgirt");
	armor->set_name(RED "���" NOR,({"red belt","belt"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corhat");
	armor->set_name(RED "��ñ" NOR,({"red hat","hat"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corboot");
	armor->set_name(RED "��Ь" NOR,({"red boot","boot"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corribb");
	armor->set_name(RED "���" NOR,({"red ribbon","ribbon"}) );
	armor->move(this_object());
	armor->wear();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
   mixed foo;
   object *inv;
   object dress; 
   int i; 
   //foo = ::hit_ob(me,victim,damage_bonus);
     if (random(victim->query("combat_exp"))<100000) 
        {  
           inv = all_inventory(victim);
           if (sizeof(inv)==0) return;
           for (i=0;i<sizeof(inv);i++){
             dress=inv[i];
             if ((string)dress->query("equipped")=="worn" ) break;
            }
           if ((string)dress->query("equipped")=="worn" )
           {
              //message_vision(YEL "$n���ϵ�"+dress->name()+"��$N����������\n" NOR,me,victim);
              dress->move(environment());
              victim->set_temp("mark/striped",1);     
              return victim->name()+YEL "���ϵ�"+dress->name()+"��$N����������\n" NOR;
           } 
          };

            
           
        return;
}
