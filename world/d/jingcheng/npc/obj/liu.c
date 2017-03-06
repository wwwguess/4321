// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_DEALER;

int check_legal_name(string arg);
int check_legal_id(string arg);

void create()
{
	set_name("������", ({ "liu yuntian" , "liu" , "yuntian" }));
	set("nickname", CYN"���ֲ�����"NOR); 
	set("long",
	"�������ǲ�ׯ���ٶ��ң�Ҳ��������Ϊ��һ˫���ֺųƲþ�����֮�£���һ�������������ӡ�\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		__DIR__"obj/cloth1.c",
		__DIR__"obj/cloth2.c",
	}));

	set("str", 30);
	set("int", 20);
	set("con", 15);
	set("dex", 20);
	set("per", 30);
	set("force", 50);
	set("max_force", 50);
	set("force_factor", 2);
	set("combat_exp", 20000);
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"������־��������˵�����㿴С�����ջ�����ɡ���\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_ding", "ding");
	
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}

void greeting(object me)
{	
	if( !me || environment(me) != environment() ) return;
 	command("say ��λ"+(string)RANK_D->query_respect(me)+"����Ҫѡ�����\n");
	command("smile");
	command("say ���꾭Ӫ�з����������⡣\n");
	say( "������Ц�����˵������λ" + RANK_D->query_respect(me)
				+ "�����������·��ɡ�\n");
}

int do_ding(string arg)
{
	string ctype, cname, ccolor, cid;
	object ob, me, gold;
	string id,newfile,filename;

        me = this_player();
	id = me->query("id");

        if(!arg || sscanf(arg,"%s %s %s %s",ctype,ccolor,cname,cid ) != 4)
        	return notify_fail("ָ���ʽ��ding <type> <color> <name> <English name>\n");
	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	if((int)me->query("created_item") >= 3)
		return notify_fail("���Ѿ�ӵ��̫��������Ʒ�ˡ�\n");
	gold = present("gold_money", this_player());
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < 1)
        	return notify_fail("������û���������ӡ�\n");
	if( !check_legal_name(cname))
		return notify_fail("");
        if( !check_legal_id(cid))
	        return notify_fail("");

	if( ccolor != "$BLK$" && 
	    ccolor != "$NOR$" &&
            ccolor != "$RED$" &&
            ccolor != "$GRN$" &&
            ccolor != "$YEL$" &&
            ccolor != "$BLU$" &&
            ccolor != "$MAG$" &&
            ccolor != "$CYN$" &&
            ccolor != "$WHT$" &&
            ccolor != "$NOR$" &&
            ccolor != "$HIR$" &&
            ccolor != "$HIG$" &&
            ccolor != "$HIY$" &&
            ccolor != "$HIB$" &&
            ccolor != "$HIM$" &&
            ccolor != "$HIC$" &&
            ccolor != "$HIW$" 
	)
	return notify_fail("��֪��Ҫʲô��ɫ��\n");
	cname = ccolor + cname;
        cname = replace_string(cname, "$BLK$", BLK);
        cname = replace_string(cname, "$RED$", RED);
        cname = replace_string(cname, "$GRN$", GRN);
        cname = replace_string(cname, "$YEL$", YEL);
        cname = replace_string(cname, "$BLU$", BLU);
        cname = replace_string(cname, "$MAG$", MAG);
        cname = replace_string(cname, "$CYN$", CYN);
        cname = replace_string(cname, "$WHT$", WHT);
        cname = replace_string(cname, "$HIR$", HIR);
        cname = replace_string(cname, "$HIG$", HIG);
        cname = replace_string(cname, "$HIY$", HIY);
        cname = replace_string(cname, "$HIB$", HIB);
        cname = replace_string(cname, "$HIM$", HIM);
        cname = replace_string(cname, "$HIC$", HIC);
        cname = replace_string(cname, "$HIW$", HIW);
        cname = replace_string(cname, "$NOR$", NOR);
        cname += NOR;
	switch( ctype ) {
		case "hat":
			newfile = read_file(__DIR__"obj/clothes/hat.c");
			break;
                case "belt":
                        newfile = read_file(__DIR__"obj/clothes/belt.c");
                        break;
                case "shoes":
                        newfile = read_file(__DIR__"obj/clothes/shoes.c");
                        break;
                case "suit":
                        newfile = read_file(__DIR__"obj/clothes/suit.c");
                        break;
                case "scarf":
                        newfile = read_file(__DIR__"obj/clothes/scarf.c");
                        break;
		default:
			return notify_fail("���ﲻ������Ҫ�Ķ�����\n");
	}
	newfile = replace_string( newfile, "������", cname);
        newfile = replace_string( newfile, "order", cid);
        newfile = replace_string( newfile, "fengyun", id);
	filename = DATA_DIR+"login/" + id[0..0] + "/" + id + "/" + id +sprintf("%d",time()) + ".c";
	if( !write_file(filename, newfile,1))
		return 0;
	ob = new(filename);
	if(ob->move(me)){
	gold->add_amount(-1);
	me->add("created_item",1);
        me->start_busy(1);
	write("�ϣ�\n");
	return 1;
	}
	return 0;
}
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
                write("�Բ����������ֱ�����һ����ʮ�������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������ֱ��������ġ�\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_id(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 3) || (strlen(name) > 20 ) ) {
                write("�Բ���Ӣ�����ֱ�����������ʮ�����֡�\n");
                return 0;
        }

	return 1;
}
