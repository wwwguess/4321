// thousand_hand.c

#include <ansi.h>

inherit NPC;
string  summon_more( object who);
void create()
{
        int i,amun;
        string *order = ({"��", "��", "��", "��", "��", "��", "֣", "��", "��", 
  "��", "��", "��", "��", "��", "��", "κ", "��", "��", "��", "��"});
          set_name( (order[random(20)]) + "����", ({ "old woman", "woman" }) );
          set("long", "����һλŮ�˴�Ĵ���ר�ŵ���ά���ΰ���\n");
          set("attitude", "friendly");
          set("title", "ǧ�ֹ���");
          set("max_gin", 500);
          set("max_kee", 500);
          set("max_sen", 500);
          set("age", 33);
          
          set("str", 35);
          set("cor", 30);
          set("cps", 25);
          
          set("combat_exp", 50000);
          set("chat_chance", 20);
          set("chat_msg", ({
                  (: random_move :)
          }) );
          set("chat_chance_combat", 4);
          set("chat_msg_combat", ({
                  (: summon_more(this_object()) :),
          }) );
          create_family("������", 82, "����");
          set_skill("throwing",100+random(90));
          set_skill("parry", 1+random(170));
          set_skill("dodge", 1+random(150));
          set_skill("unarmed", 1+random(100));
          set_skill("nine-moon-claw", 1+random(80));
          map_skill("unarmed", "nine-moon-claw");
          setup();
          carry_object("/obj/cloth")->wear();
          add_money("silver", 50);
          amun = random(5)+1;
          for(i=1; i<= amun; i++){
                  carry_object(__DIR__"obj/pearl")->wield();
          }
          
  }
  
  string summon_more(object who)
  {
          int i;
          object *enemy;
          object another;
          if((string) environment(who)->query("outdoors") == "girlvillage")
          {
          seteuid(getuid());
          another = new(__DIR__"thousand_hand");
          another->move(environment(who));
          message_vision(another->name()+ "���˹�����\n"
                  , this_object() );
          enemy = who->query_enemy();
          i = sizeof(enemy);
          while(i--) {
                 if( enemy[i] && living(enemy[i]) ) {
                         another->kill_ob(enemy[i]);
                         if( userp(enemy[i]) ) enemy[i]->fight_ob(another);
                         else enemy[i]->kill_ob(another);
                 }
          }
          set_leader(who);
          return "1";
          }
          else
          return "0";
          
          
  }
  
  void init()
  {       object ob;
          if( interactive( ob = this_player())
  && (string) environment(ob)->query("outdoors") == "girlvillage"
  )
          {
          if( (string)ob->query("gender") == "����")
          {
          command("say �󵨣�����̤��Ů�˴壡\n");
          kill_ob(ob);
          }
          }
  }
                                                                                       