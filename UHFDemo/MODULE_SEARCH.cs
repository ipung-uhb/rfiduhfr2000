﻿
using System;

namespace UHFDemo
{
    public class MODULE_SEARCH
    {
        private byte[] data;

        byte[] mod_ip; // 4
        byte[] mod_name; // 6
        byte[] reserve; // 2
        byte mod_ver; //1

        // 为了关联 mod_cfg
        byte[] mod_mac;// 6
        byte[] pc_mac;// 4

        int writeIndex;
        int readIndex;

        public MODULE_SEARCH(byte[] parseData, byte[] modMac, byte[] pcMac)
        {
            data = new byte[parseData.Length];
            this.data = parseData;
            writeIndex = 0;

            mod_ip = new byte[4];
            Array.Copy(data, writeIndex, mod_ip, 0, mod_ip.Length);
            writeIndex += mod_ip.Length;

            mod_name = new byte[data.Length - 7]; // ip[4] + name[N] + reverse[2]+ver[1]
            Array.Copy(data, writeIndex, mod_name, 0, mod_name.Length);
            writeIndex += mod_name.Length;

            reserve = new byte[2];
            Array.Copy(data, writeIndex, reserve, 0, reserve.Length);
            writeIndex += reserve.Length;

            mod_ver = data[writeIndex++];

            this.mod_mac = new byte[6];
            Array.Copy(modMac, 0, this.mod_mac, 0, modMac.Length);

            this.pc_mac = new byte[6];
            Array.Copy(pcMac, 0, this.pc_mac, 0, pcMac.Length);
        }

        public void Update(MODULE_SEARCH addData)
        {
            
        }

        public string ModName
        {
            get { return System.Text.Encoding.Default.GetString(mod_name); }
        }

        public string ModIp
        {
            get
            {
                return String.Format("{0}.{1}.{2}.{3}",
              Convert.ToInt32(mod_ip[0]),
              Convert.ToInt32(mod_ip[1]),
              Convert.ToInt32(mod_ip[2]),
              Convert.ToInt32(mod_ip[3]));
            }
        }

        public string ModMac
        {
            get { return CCommondMethod.ToHex(mod_mac, "", ":"); }
        }

        public string ModVer
        {
            get { return Convert.ToInt32(mod_ver).ToString(); }
        }
        
        public string PcMac
        {
            get
            {
                return CCommondMethod.ToHex(pc_mac, "", ":");
            }
        }
    }
}