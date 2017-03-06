inherit NPC;

int ask_me();
int accept_fight(object ob);
int checking(object me, object ob);
void create()
{
	set_name("����", ({ "ku rong","ku"}) );
	set("gender", "����" );
	set("class", "bonze");
	set("age", 100);
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);

	set("kee", 3000);
	set("max_kee", 3000);
	set("gin", 1000);
	set("max_gin", 1000);
	set("force", 5000);
	set("max_force", 5000);
	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 1000000);

	set_skill("force", 150);
	set_skill("hunyuan-yiqi", 150);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("parry", 100);
	set_skill("finger", 105);
	set_skill("staff", 150);
	set_skill("liumai-shenjian", 100);
	set_skill("weituo-gun", 150);
	set_skill("buddhism", 150);
	set_skill("literate", 150);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "liumai-shenjian");
	map_skill("finger", "liumai-shenjian");
	map_skill("staff", "weituo-gun");
	prepare_skill("finger","liumai-shenjian");	
	
	set("inquiry" ,([
	"������" : (: ask_me :),
	"��������" : (: ask_me :),
	"�����񽣽���" : (: ask_me :),
	]));

	setup();
//	carry_object("/d/baituo/obj/jiasha")->wear();
}

int ask_me()
{
        if ((int)this_player()->query_temp("marks/find_temp")&&this_player()->query_temp("marks/ask_temp3")) 
		{
        	say(
"���ٿ���" + this_player()->name() + "һ�ۣ�˵����\n"
"��λʩ����Ȼ������ʩ������ʤ�����ľͿɵõ��������ס�\n");
       		return 1;
        }
}

int accept_fight(object ob)
{
        object me;

        me = this_object();
      
        if( ob->query_temp("marks/find_temp")&&ob->query_temp("marks/ask_temp3") ) {
           say(ob->name() + "�Կ���˵���ðɣ���" 
             "�Ҿ�ͬ���д꼸�аɣ��㵽Ϊֹ��\n");
	  remove_call_out("checking");
          call_out("checking", 1, me, ob);
          return 1;
        }
        else
    	  return 0;
}

int checking(object me, object ob)
{

        object obj;
        int my_max_qi, his_max_qi;
        my_max_qi  = (int)me->query("max_kee");
        his_max_qi = (int)ob->query("max_kee");

        if (me->is_fighting()) 
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1; 

        if (( (int)me->query("kee")*100 / my_max_qi) <= 50 ) 
        {
                say(
                  "����˵��ʩ�����ֹ�Ȼ���������������\n"
                  "�Ȿ������������ȥ�ɡ�\n"
                );
                obj= new("/d/tianlongsi/obj/liumai-jianpu"); 
                obj->move(ob);
                message_vision("$N����$nһ���顣\n", me, ob);
                return 1;
        }
        if (( (int)ob->query("kee")*100 / his_max_qi) < 50 ) 
        {
                say(
                   "����˫�ֺ�ʮ������Եһ��������ʩ����ذɡ�\n"
                );
                message_vision("$N�Կ��ٴ�ʦ���������ؿ���һ��ͷ���뿪Ĳ���á�\n", ob);
                ob->move("/d/tianlongsi/banruotai");
                return 1;
        }
        return 1;
}
